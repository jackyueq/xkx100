
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�����µ���", ({ "tianlongsi dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 18);
       set("long",
               "����һ�������µ�Сʦ����\n");
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
			say( "�����µ���˵������λ" + RANK_D->query_respect(ob)
          + "������������µĻ������Կ�"BRED"(help dali)"NOR"��\n");
			break;
		case 1:
			say( "�����µ���˵����һ��ָ�������������Ƿ��ž�ѧ����Ҫ������ѧ�������񽣵Ļ���
  ���ܰ���Ⱥ�ۡ�\n");
			break;
		case 2:
			say( "�����µ���˵��������軨��������������֮��ȥ�軨԰���ͻ���ƷƷ�裬��Ҳ��ʧ
Ϊһ�����¡�\n");
			break;	
	}
}
