inherit NPC;
#include <ansi.h>

void create()
{
       set_name("ѩɽ����", ({ "xueshan dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ�������ѩɽ���ӡ�\n");
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
			say( "ѩɽ�ɵ���˵������λ" + RANK_D->query_respect(ob)
            + "�����ѩɽ���𣬿��Կ�"BRED"(help mizong)"NOR"��\n");
			break;
		case 1:
			say( "ѩɽ�ɵ���˵�������ŵĻ��浶�����¼���Ե��Ĺ���\n");
			break;
		case 2:
			say( "ѩɽ�ɵ���˵��������ѩɽ�书�����������ѧ��һ�������ܳ���ͷ���ˡ�\n");
			break;
	}

}
