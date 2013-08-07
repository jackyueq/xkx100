// flower.h
// Last Modified by winder on Aug. 18 2002

void init()
{
	remove_call_out("do_check");
	call_out("do_check", 60+random(120));
	add_action("do_check", "check");
}
int do_check()
{
	object env;
	env=environment(this_object());
	if(userp(env))
	{
		if(query("flower_aroma")>3)
		{
			message_vision("$N���ϵ�$n�ѿ�ή�ˡ�\n", this_player(),this_object());	
			destruct(this_object());
			return 1;
		}
		if((string)file_name(environment(env))!="/d/city/huadian")
		{
			message_vision("$N���ϵ�$n����һ�������˵����㡣\n", env,this_object());		
			add("flower_aroma",1);
		}
		remove_call_out("do_check");
		call_out("do_check", 60+random(120));
		return 1;
	}
	else 
	{
		message_vision("һ��紵������$N�����ˡ�\n", this_object());	
		destruct(this_object());
		return 1;
	}
}

