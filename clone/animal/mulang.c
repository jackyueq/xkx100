//lang.c ��
// Last Modified by winder on Aug. 1 2002

// inherit NPC_TRAINEE;
inherit "/inherit/char/trainee";

void create()
{
	set_name("ĸ��", ({ "mu lang","lang", "wolf" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 15);
	set("long", "����һͷ��ɫ��ĸ�ǣ����ú�ɫ���۾������㣬��ʱ�������˵�ս��������\n");
	set("msg_fail","$nת����������$N��ҧ��$Næ������");
	set("msg_succ","$Nһ���֣�$n��ͷ����Ŷ�������");
	set("msg_trained","$n�����ɫ����ͷ������$N�Ľ�");
	set("auto_follow",1);
	set("wildness",9);
	set("attitude", "aggressive");
	
	set("str", 29);	
	set("con", 40);
	set("dex", 45);	
	set("int", 10);

	set("combat_exp", 14000);

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor",  20);

	set("chat_chance", 10);
	set("chat_msg", ({
		"ĸ�Ƿ���һ���ƽУ�������ʱ��Ҫ��������\n",
		"ĸ�ǵ�˫Ŀ�ںڰ������ź�⣬������ע�������һ��һ����\n",
		"����~~~~��ĸ�Ƿ���һ���ƽС�\n",
	}) );
	
	setup();
}


