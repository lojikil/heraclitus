import java.net.URL;
import java.security.cert.Certificate;
import java.security.cert.CertificateExpiredException;
import java.security.cert.X509Certificate;
import javax.security.auth.x500.X500Principal;
import javax.net.ssl.HttpsURLConnection;

public class chainCheck {

    /* from this StackOverflow, but explempary of how OWASP & others
     * have demoed it before...
     * http://stackoverflow.com/questions/7199129/how-to-get-server-certificate-chain-then-verify-its-valid-and-trusted-in-java
     */

    /**
     * @param args
     */
    public static void main(String[] args) {
        chainCheck tester = new chainCheck();
        try {
            tester.testConnectionTo("https://www.nvisium.com");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public chainCheck() {
        super();
    }

    public void testConnectionTo(String aURL) throws Exception {
        URL destinationURL = new URL(aURL);
        HttpsURLConnection conn = (HttpsURLConnection) destinationURL
                .openConnection();
        conn.connect();
        Certificate[] certs = conn.getServerCertificates();
        for (Certificate cert : certs) {
            X500Principal subject = ((X509Certificate)cert).getSubjectX500Principal();
            X500Principal issuer = ((X509Certificate)cert).getIssuerX500Principal();
            System.out.println("subject: " + subject.getName());
            System.out.println("issuer: " + issuer.getName());
            if(cert instanceof X509Certificate) {
                try {
                    ( (X509Certificate) cert).checkValidity();
                    System.out.println("Certificate is active for current date");
                } catch(CertificateExpiredException cee) {
                    System.out.println("Certificate is expired");
                }
            }
            System.out.println("-----");
        }
    }
}
