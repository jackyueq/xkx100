// tiger.c �ϻ�
// Last Modified by Winder on May. 15 2001
// Date: Sep.22 1997

inherit NPC;

void create()
{
	set_name("�ϻ�", ({ "tiger", "laohu", "hu" }) );
	set("race", "����");
	set("age", 20);
	set("long", @LONG
һֻ����ͻ�����ΰ���ˡ�

         _.-'"''--..__.("\-''-'")
 ('.__.-' (  *  ) .-'    ( @ _@'
  `-..-''.' _.'  (   _.  `(._Y_)
         `. `._`--\  \_-.._`--'.._
          `-.!))  `.(il)   ''-.(li)

LONG);

//	set("attitude", "aggressive");
	set("attitude", "peace");
	set("combat_exp", 30000);
	set_temp("apply/attack", 180);
	set_temp("apply/defense", 180);
	set_temp("apply/damage", 90);
	set_temp("apply/armor", 50);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"�ϻ��ڿ�Ѳ���ŵ�����������ҳ���\n",
		"�ϻ����쳤Х������ɽ�ȣ���Ҷ��׹��\n",
	}) );
}


void die()
{
	object ob, corpse;
	message_vision("$N�������춯�ص�һ����Х����ص��ڵ��ϣ����ˣ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/vegetable/hugu");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
