inherit NPC;
#include <ansi.h>

void create()
{
       set_name("���յ���", ({ "baituo dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һλ��ò�Źֵİ���ɽ���ӡ�\n");
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
			say( "����ɽ����˵������λ" + RANK_D->query_respect(ob)
            + "��������ɽ�𣬿��Կ�"BRED"(help baituo)"NOR"��\n");
			break;
		case 1:
			say( "����ɽ����˵������������ŷ����Ķ��ž�����󡹦����������ѧ�еľ�������
�����ڹ��仯��΢����������⹦�Ʒ���������ᣬ�����иգ���ʽ�����������޴�\n");
			break;
		case 2:
			say( "����ɽ����˵������ׯ��ŷ���˷������ԣ����������ݳ����ι䣬����԰�����
Ȼ����������������ɽ��\n");
			break;
	}

}
