inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��ػ����", ({ "tiandihui bangzhong", "bangzhong" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ����İ�С����ػ���ڡ�\n");
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
			say( "��ػ����˵������λ" + RANK_D->query_respect(ob)
            + "�������ػ��𣬿��Կ�"BRED"(help tiandihui)"NOR"��\n");
			break;
		case 1:
			say( "��ػ����˵����������ػἴ��Ϊ������͢����ʿ��\n");
			break;
		case 2:
			say( "��ػ����˵�����ܶ����½��ϵĳ�����������Ѫ��ץ���𽭺�����С֮���������ҡ�\n");
			break;
	}

}
