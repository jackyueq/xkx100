
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("С�л�", ({ "xiao jiaohua", "xiao" }) );
       set("gender", "����" );
       set("age", 16);
       set("long",
               "����һ���ܻ����С�л��������������á�\n");
       set("combat_exp", 10500);
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
			say( "С�л�����ͷ��˵������λ" + RANK_D->query_respect(ob)
                   + "�����������ؤ���𣬿��Կ�"BRED"(help gaibang)"NOR"��\n");
			break;
		case 1:
			say( "С�л�ü��ɫ���˵���� ���µ�һ��ô, ��Ȼ������ؤ���ˡ�
 ����ʮ���ƣ��򹷰�������ؤ��ľ�ѧ��\n");
			break;
		case 2:
			say( "С�л�ü��ɫ���˵���� ���µ�һ��ô, ��Ȼ������ؤ���ˡ�
ؤ�ﰵ����ͨ�˴Ψ�б�����Ӳ���ʹ�á�\n");
			break;	
	}

}
