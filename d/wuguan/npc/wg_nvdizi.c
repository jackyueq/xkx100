
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��ĹŮ����", ({ "gumu dizi", "dizi" }) );
       set("gender", "Ů��" );
       set("age", 16);
       set("long",
               "������һλ��ĹŮ���ӣ�һ����¡���\n");
       set("combat_exp", 30500);
       set("attitude", "friendly");
 
       setup();

       carry_object("/clone/cloth/cloth/moon-dress")->wear();
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
			say( "��ĹŮ����΢΢Ц��˵������λ" + RANK_D->query_respect(ob)
          + "���������Ĺ���ޣ����Կ�"BRED"(help gumu)"NOR"��\n");
			break;
		case 1:
			say( "��ĹŮ����˵������Ĺ���峾���ף���òǷ���߻��Ǽ����
����������Ϊ�á�\n");
			break;
		case 2:
			say( "��ĹŮ�������������˵ʦ�����Ѿ���Ϊ���������Ĵ��ˣ�
��Ĺ�ɵ���Ӧ���͵�ס��į���ܷ�Ŭ�������˹�Ĺ��\n");
			break;
	}

}
