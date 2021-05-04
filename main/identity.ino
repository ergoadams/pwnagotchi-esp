
class Keypair {  
  public:
    Keypair();
    String priv_key;
    String pub_key;
    String pub_key_pem;
    String pub_key_pem_b64;
    String fingerprint;
};

Keypair::Keypair() {
  if (!LITTLEFS.exists("/id_rsa.pub")) {
    Serial.println("WARN: should generate rsa public key");
  }
  if (!LITTLEFS.exists("/id_rsa.priv")) {
    Serial.println("WARN: should generate rsa private key");
  }  
}
