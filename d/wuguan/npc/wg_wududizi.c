inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�嶾����", ({ "wudu dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long", "����һ�������������嶾���ӡ�\n");
       set("combat_exp", 25000);
       set("attitude", "friendly");
       setup();
        carry_object("clone/cloth/cloth")->wear();

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
		case 0: say("�嶾�̵��Ӻٺ�˵���������嶾���Ĵ�����ɲ��С���λ"+RANK_D->query_respect(ob)
+"����ͨ�Ļ������Կ�"BRED"(help wudujiao)"NOR"��\n");
			break;
		case 1: say("�嶾�̵��Ӻٺ�˵�������Ŷ�ҩ���棬����ʤ���������µ�һ�ն������ɡ�������..........\n");
			break;	
		case 2: say("���޵��Ӽ�Ц������˵�򶾿�ĳ�������嶾�̵ı��\n");
			break;
	}

}
