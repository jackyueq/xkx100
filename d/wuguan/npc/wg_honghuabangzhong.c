inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�컨�����", ({ "honghuahui bangzhong", "bangzhong" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ����Ŀ���ĺ컨����ڡ�\n");
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
			say( "�컨�����˵������λ" + RANK_D->query_respect(ob)
            + "�����컨���𣬿��Կ�"BRED"(help honghua)"NOR"��\n");
			break;
		case 1:
			say( "�컨�����˵������ʮ��·׷�������������˫���Ƕ������޳������ĵ����书��\n");
			break;
		case 2:
			say( "�컨�����˵�����ܶ����¼���ĳ����������仨ʮ�������𽭺�����С֮���������ҡ�\n");
			break;
	}

}
