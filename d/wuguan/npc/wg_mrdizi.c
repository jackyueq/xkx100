// Last Modified by Sir on 9/17/2001
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("Ľ�ݵ���", ({ "murong dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 16);
       set("long",
               "����һ������������꣬������ǿ��׳��\n");
       set("combat_exp", 30000);
       set("attitude", "friendly");
 
       setup();
 carry_object("/clone/cloth/cloth")->wear();
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
			say( "Ľ�ݵ������յ���Ľ��ɽׯ���������˾����ĵط�����λ" + RANK_D->query_respect(ob)
             + "���β���Ͷ��Ľ��ɽׯ�����Կ�"BRED"(help murong)"NOR"��\n");
			break;
		case 1:
			say( "Ľ�ݵ������յ�����������Ľ��ɽׯ�Ļ�ʩˮ��������񶴣�����ѧ��
�������׵��书��\n");
			break;
		case 2:
			say( "Ľ�ݵ������յ���Ľ��ɽׯ���������˾����ĵط�����λ" + RANK_D->query_respect(ob)
             + "���β�����Ľ��ɽׯ�����ն���ѧ�ɶ�ת���Ƶľ����书���������֡�\n");
			break;	
	}

}
