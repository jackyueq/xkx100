inherit NPC;
#include <ansi.h>

void create()
{
       set_name("���ư����", ({ "tiezhang dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "һ��һ�����������ư���ӡ�\n");
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
			say( "���ư����˵������λ" + RANK_D->query_respect(ob)
            + "��������ư��𣬿��Կ�"BRED"(help tiezhang)"NOR"��\n");
			break;
		case 1:
			say( "���ư����˵��������ÿ����������֮ʱ���ش������İ��ı�����������������Ϸ壬
һ���ָ�һ����ʯ���б������ǲ��١���\n");
			break;
		case 2:
			say( "���ư����˵�������������Ƴ������£��������񶾣��뽵��ʮ���ơ���Ȼ�����Ʋ���
���¡�\n");
			break;
	}

}
