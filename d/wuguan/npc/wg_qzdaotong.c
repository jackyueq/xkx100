
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("ȫ���ͯ", ({ "daotong", "tong" }) );
       set("gender", "����" );
       set("age", 16);
       set("long",
               "����һ��ʮ�߰����С��ͯ��һ����������ӡ�\n");
       set("combat_exp", 2500);
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
			say( "ȫ���ͯ��Ц������λ" + RANK_D->query_respect(ob)
          + "�������ȫ��̵Ļ������Կ�"BRED"(help quanzhen)"NOR"��\n");
			break;
		case 1:
			say( "ȫ���ͯ�����˵������ʦ���������ֺš�����ͨ�����״λ�ɽ
�۽������ܶ�а���������ϵۡ���ؤ������书���µ�һ�ĳƺš�\n");
			break;
		case 2:			
			say( "ȫ���ͯ�����������ϰ���칦���������Ŷ��������Գ���������������Ŷ��\n");			
			break;	
	}

}
