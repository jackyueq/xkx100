inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�����ֵ���", ({ "nanshaolin dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ����Ŀ���Ĵ���С�\n");
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
			say( "�����ֵ���˵������λ" + RANK_D->query_respect(ob)
            + "������������𣬿��Կ�"BRED"(help nanshaolin)"NOR"��\n");
			break;
		case 1:
			say( "�����ֵ���˵�������׽����ϴ�衷������Ϊ��������֮�����ഫΪ��Ħ��ʦ������\n");
			break;
		case 2:
			say( "�����ֵ���˵�����������书�����������ѧ��һ�������ܳ���ͷ���ˡ�\n");
			break;
	}

}
