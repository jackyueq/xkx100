
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("���̰���", ({ "mingjiao bangzhong", "bangzhong" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ����ǿ��׳���ӡ�\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
 
       setup();
 carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(3) ) {
		case 0:
			say( "���̰���˵�������µ�һ��, �����������̡�����λ" + RANK_D->query_respect(ob)
              + "�����������̣����Կ�"BRED"(help mingjiao)"NOR"��\n");
			break;
		case 1:
			say( "���̰���˵����Ǭ����Ų�ƣ�ʥ�����񹦿��Ƕ������ֵľ�ѧ����\n");
			break;
		case 2:
			say( "���̰���˵���������Ĵ󻤽̷�������һ�ֻ��������\n");
			break;	
	}

}
