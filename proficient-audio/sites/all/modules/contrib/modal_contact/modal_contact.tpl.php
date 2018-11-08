<?php
/**
 * @file
 * Template file.
 *
 * @param $enabled  true or false.
 * @param $class  array of classes to apply to anchor tag.
 * @param $align  left or right.
 * @param $top  distance from the top; include unit.
 * @param $image  image href.
 * @param $alt  image alt text.
 * @param $deny  paths to hide.
 * @param $allow  paths to show.
 * // Computed from image.
 * @param $height  image height in pixels.
 * @param $width  image width in pixels.
 */

global $base_url;
$my_path = drupal_get_path('module', 'modal_contact');
//error_reporting(0); session_start();

if(isset($_POST['contact_token'])){
	$from = $_POST['contact_email'];
	$name = $_POST['contact_name'];
	$message = $_POST['contact_content'];
	$copyme = $_POST['contact_copy'];
	
	if($_POST['captcha'] == $_POST['theanswer']){
		if(cf_domain_exists($_POST['contact_email'])){		
			if(cf_dosend_mailer($from, $name, $message, $copyme)){
				$msg['status']  = 'success';
				$msg['message'] = t('The message has been sent successfully.');
			}
			else {
				$msg['status']  = 'error';
				$msg['message'] = t('Not send, Please contact administrator directly to: ').'<a href="mailto:'.$email.'">'.$email.'</a>';
			}
		}
		else {
			$msg['status']   = 'error';
			$msg['message'] = t('Not send, Please check your provided email.');
		}
	}
	else {
		$msg['status']   = 'error';
		$msg['message'] = t('Not send, Challenge is Invalid.');
	}
		
	header("Content-Type: application/json");
	echo json_encode( $msg );
	exit;
}
$numb1 = rand(0,99);
$numb2 = date("H",time());

$answer = $numb1+$numb2;
 
?>
<?php if ($enabled):?>

<div id='modal_contact'>

    <meta http-equiv="content-type" content="text/html;charset=UTF-8" />
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=10" />
    <script type='text/javascript' src='<?php echo $base_url.'/'.$my_path;?>/assets/js/jquery/jquery.js'></script>
    <script type='text/javascript' src='<?php echo $base_url.'/'.$my_path;?>/assets/js/jquery/jquery-migrate.min.js'></script>
	<script type='text/javascript' src='<?php echo $base_url.'/'.$my_path;?>/assets/js/bootstrap.min.js'></script>
	<script type='text/javascript' src='<?php echo $base_url.'/'.$my_path;?>/assets/js/jquery.modal.js'></script>
	<link rel='stylesheet' href='<?php echo $base_url.'/'.$my_path;?>/assets/css/jquery.modal.css' type='text/css' media='all' />
	<link rel='stylesheet' href='<?php echo $base_url.'/'.$my_path;?>/assets/css/modal_contact.css' type='text/css' media='all' />
	<link rel='stylesheet' href='<?php echo $base_url.'/'.$my_path;?>/assets/css/color/<?php print $theme;?>.css' type='text/css' media='all' />
	<script>					
		(function($){
			$(document).ready(function(){
				var inst = $('[data-remodal-id=modal]').remodal();
			});
		}(jQuery));								
	</script>

  <a
    href='#form_modal'
    class='modal_contact-<?php print $align; ?>'
    style='top: <?php print $top ?>; height: <?php print $height;?>px; width: <?php print $width;?>px;'>
      <img
        alt='<?php print $alt; ?>'
        src='<?php print $image; ?>'
        height='<?php print $height;?>'
        width='<?php print $width;?>' />
  </a>

    <div id="form_modal" class="remodal" data-remodal-id="form_modal">
        <div class="form_modal-inner">
            <link href="<?php echo $base_url.'/'.$my_path;?>/assets/css/bootstrap.css" rel="stylesheet" media="screen">
			<style>
                .bootstrap-wrapper .form-horizontal .control-label { margin-bottom:5px; }
			 	a:hover {text-decoration:none;}
            </style>

            <div class="bootstrap-wrapper">
                <div class="container-fluid custom-width">
                    <div class="row"><br/></div>
                    
                    <form id="form_modal_1" name="form_modal_1" class="form-horizontal" role="form" onSubmit="return false;">
                    
                        <div class="row">
                        	<div id="selected-column-1" class="droppedFields min-height drop_dashed activeDroppable">
                            	<div class="form-group row droppedField">
	                                <div align="left"><h2 class="text-form_modal"><?php print $title;?></h2></div>
    	                        	<div align="left" class="text-form_modal"><?php print $pretext;?></div>
                            	</div>
                            </div>    
                        </div>

                        <div class="row">
                            <div id="selected-column-1" class="droppedFields min-height drop_dashed activeDroppable">
                                <div class="form-group row droppedField">
                                    <label for="name" class="form-label-lg control-label pull-left text-form_modal"><?php echo t('Full Name');?><span class="stared"></span></label>										
                                    <input type="text" name="contact_name" class="form-control ctrl-textbox input-lg" placeholder="<?php echo t('Enter Full Name');?>" required alt="required" id="name">
                                </div>
                            
                                <div class="form-group row droppedField">									
                                    <label for="email" class="form-label-lg control-label pull-left text-form_modal"><?php echo t('Email Address');?><span class="stared"></span></label>
                                    <input type="email" name="contact_email" class="form-control ctrl-textbox input-lg" placeholder="<?php echo t('Enter Email Address');?>" required alt="required" id="email">
                                </div>
                            
                                <div class="form-group row droppedField">									
                                    <label for="message" class="form-label-lg control-label pull-left text-form_modal"><?php echo t('Message');?><span class="stared"></span></label>										
                                    <textarea name="contact_content" class="form-control ctrl-textarea input-lg" placeholder="<?php echo t('Enter Message');?>" rows="5" required id="message"></textarea>
                                </div>
                                
                                <div class="form-group row droppedField">
                                	<label for="captcha" class="form-label-lg control-label pull-left text-form_modal"><?php echo t('Challenge');?><span class="stared"></span></label>
                                    <br clear="all" />
                                    <div id="captcha-wrap">
                                        <div class="captcha-box">
                                            <span id="captchaimg"></span>
                                        </div>
                                        <div class="text-box">
                                            <label for="captcha" class="form-label-lg pull-left"><?php echo t('Type the Challenges');?>:</label>
                                            <input type="text" class="form-control ctrl-textbox" name="captcha" id="captcha" required alt="required">
                                        </div>
                                        <div class="captcha-action">
                                            <img src="<?php echo $base_url.'/'.$my_path;?>/assets/imgs/refresh.jpg" title="<?php echo t('Click to refresh Challenge');?>" id="refresh" />
                                        </div>
                                    </div>
                                </div>

                                <div class="form-group row droppedField">									
                                    <label for="copy" class="form-label-lg control-label pull-left text-form_modal"><input type="checkbox" name="contact_copy" value="yes" id="copy" /> <?php echo t('Send me copy to my email?');?></label>                                  	
                                </div>
                            
                                <div class="form-group row droppedField">
                                    <button id="submit_form_modal" type="button" class="btn ctrl-btn btn-lg btn-block btn-color-form_modal btn-info"><?php echo t('Submit');?></button>
                                </div>
                            </div>							
                        
                            <div class="text-center" id="loading-form_modal"></div>

                            <input type="hidden" name="contact_token" value="<?php echo uniqid();?>" />
                            <input type="hidden" name="callback" value="modal_contact_form_submit" />
                            <input type="hidden" name="wrapper" value="modal-contact-form" />
                            <input type="hidden" name="theanswer" id="theanswer" value="<?php //echo $answer;?>" />

                        </div>															
                    </form>					
                </div>
            </div>

		<script type="text/javascript">

            jQuery(document).ready(function(){
			
				var captcha = randomString();
				jQuery("#captchaimg").html('<span id="caps">'+captcha+'</span>');
				jQuery("#theanswer").val(captcha);

				jQuery("img#refresh").click(function(e){
					e.preventDefault();
					reloadCaptcha();
				});

				function reloadCaptcha(){
					var captcha = randomString();
					jQuery("#captchaimg").html('<span id="caps">'+captcha+'</span>');
					jQuery("#theanswer").val(captcha);
				}

				function randomString() {
					var rands = Math.floor((Math.random() * 10000) + 2);
					var chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghiklmnopqrstuvwxyz";
					var string_length = 6;
					var randomstring = rands+' ';
					for (var i=0; i<string_length; i++) {
						var rnum = Math.floor(Math.random() * chars.length);
						randomstring += chars.substring(rnum,rnum+1);
					}
					return randomstring;
				}

				jQuery('span#caps').each(function() {
					var word = jQuery(this).html();
					var index = word.indexOf(' ');
					if(index == -1) {
						index = word.length;
					}
					jQuery(this).html('<span class="first-word">' + word.substring(0, index) + '</span>' + word.substring(index, word.length));
				});

                jQuery("#submit_form_modal").on("click",function(){                    

                    var form_name = "#form_modal_1";
                    var valid = 1;
                    var loader_image = "<img  src='<?php echo $base_url.'/'.$my_path;?>/assets/imgs/loader.gif' />";
                    var values = {};
                
                    jQuery.each(jQuery(form_name).serializeArray(), function(i, field) {
                        values[field.name] = field.value;
                    });
    
                    jQuery.each(values, function(name,value) {
                        var field_name = form_name+" [name="+name+"]";
                        var label_name = jQuery(form_name+" [name="+name+"]").prev().text();
                        val = jQuery(field_name).attr("required");
                        if (typeof val !== "undefined") {
                            if(value == ""){
                                valid = 0;
                                jQuery(field_name).css("border-color","red");
                                jQuery("#loading-form_modal").html("<div class='errormsg'>A required field ("+jQuery.trim(label_name)+") is empty!</div>");													
								reloadCaptcha(); 
                                return false;
                            }
							else if(jQuery("#message").val() != "" && jQuery("#message").val().length < 15){
                                valid = 0;
                                jQuery(field_name).css("border-color","red");
                                jQuery("#loading-form_modal").html("<div class='errormsg'><?php echo t('Message must be 15 chars or more!');?></div>"); 
                                reloadCaptcha();
								return false;
							}
							else if(jQuery("#message").val() != "" && jQuery("#message").val().length > 500){
                                valid = 0;
                                jQuery(field_name).css("border-color","red");
                                jQuery("#loading-form_modal").html("<div class='errormsg'><?php echo t('Message can\'t be more then 500 chars!');?></div>"); 
								reloadCaptcha();
                                return false;
							}
							else if(jQuery("#captcha").val() != jQuery("#theanswer").val()){
                                valid = 0;
                                jQuery(field_name).css("border-color","red");
                                jQuery("#loading-form_modal").html("<div class='errormsg'><?php echo t('Challenge is Invalid!');?></div>");
								reloadCaptcha();
                                return false;
							}
                            else{
                                jQuery(field_name).css("border-color","#cccccc");
                            }
                        }
                        if((name.indexOf("contact_email") !== -1) && jQuery.trim(value)!= ""){
                            if(!isValidEmailAddress(jQuery.trim(value))){
                                valid = 0;
                                jQuery(field_name).css("border-color","red");
                                jQuery("#loading-form_modal").html("<div class='errormsg'><?php echo t('Email address is invalid');?></div>"); 
                                reloadCaptcha();
								return false;
                            }
                            else{
                                jQuery(field_name).css("border-color","#cccccc");
                            }
                        }
                    
                        if((name.indexOf("contact_email") !== -1) && jQuery.trim(value)=="" && typeof val === "undefined"){
                            jQuery(field_name).css("border-color","#cccccc");
                        }
                    });
                
                    if(valid == 1){
                        var ajaxurl = "<?php echo $base_url;?>/";
                        jQuery("#loading-form_modal").html(loader_image);
                        jQuery.ajax({
                            url : ajaxurl,								
                            dataType : "json",
                            type : "POST",
                            data : jQuery("#form_modal_1").serialize(),
                            success : function(response){
                                jQuery("#loading-form_modal").html("");
                                if(response.status == "success"){
                                    jQuery("#loading-form_modal").html("<div class='successmsg'>"+response.message+"</div>");
                                    jQuery("#form_modal_1")[0].reset();
									reloadCaptcha();
                                }
                                if(response.status == "error"){
                                    reloadCaptcha();
									jQuery("#loading-form_modal").html("<div class='errormsg'>"+response.message+"</div>"); 
                                }
                            }
                        });
                    }
                });
            });
            
            function isValidEmailAddress(emailAddress) {
				var filter = /^[a-zA-Z0-9.!#$%&#038;'*+\/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$/;

				if (filter.test(emailAddress)) {
					return true;
				}
				else {
					return false;
				}
            }
        </script>

	</div>
</div>

<?php endif;
