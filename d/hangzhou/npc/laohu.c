// laofu.c �ϻ�
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("�ϻ�", ({ "laohu", "tiger","hu" }) );
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
        set("attitude", "aggressive");

        set("combat_exp", 30000);
        set("neili",800);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 1000);

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
