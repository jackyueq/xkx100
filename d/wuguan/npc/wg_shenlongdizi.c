inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�����̵���", ({ "shenlong dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long", "����һ�����������������̵��ӡ�\n");
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
		case 0: say("�����̵��Ӻٺ�˵�������������̣��Ĵ�����ɲ��С���λ"+RANK_D->query_respect(ob)
+"����ͨ�Ļ������Կ�"BRED"(help shenlong)"NOR"��\n");
			break;
		case 1: say("�����̵��Ӻٺ�˵�����ߵ��湦�������µ�һ�ն����书��������..........\n");
			break;	
		case 2: say("�����̵��Ӽ�Ц������������������̵Ļ������ƴ��У���Ҫ�������¶�����\n");
			break;
	}

}
