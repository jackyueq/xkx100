inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��ң����", ({ "xiaoyao dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ���������ң���ӡ�\n");
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
			say( "��ң�ɵ���˵������λ" + RANK_D->query_respect(ob)
            + "�������ң���𣬿��Կ�"BRED"(help xiaoyao)"NOR"��\n");
			break;
		case 1:
			say( "��ң�ɵ���˵�����貨΢������������ʮ���Զ��ţ��ھ��б�һ���죬
�Ų���̤����ʮ����һ���졣��������Ѹ�ݣ������貨���У����������������Ѽ���\n");
			break;
		case 2:
			say( "��ң�ɵ���˵������ڤ�񹦲���������潣����Ƿ���ѧ��֮�󶨿ɶ������֡�\n");
			break;
	}

}
