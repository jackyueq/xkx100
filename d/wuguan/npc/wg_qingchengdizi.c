inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��ǵ���", ({ "qingcheng dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ����ĸ�������ǵ��ӡ�\n");
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
			say( "����ɵ���˵������λ" + RANK_D->query_respect(ob)
            + "�����������𣬿��Կ�"BRED"(help qingcheng)"NOR"��\n");
			break;
		case 1:
			say( "����ɵ���˵����������Խ�������������û��һ�����������ǲ��ܰ���������µġ�\n");
			break;
		case 2:
			say( "����ɵ���˵�������־Ŵ�ͳ���ʮ�����������к��еļ��ܣ�ѧ�д�ɺ�������ҵ���Ӧ��е��
����ʹ�õĻ���Ц�������ǲ�Զ�����ˡ�\n");
			break;
	}

}
