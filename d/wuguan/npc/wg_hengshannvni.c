inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��ɽŮ��", ({ "hengshan nvni", "nvni" }) );
       set("gender", "Ů��" );
       set("age", 26);
       set("long",
               "������һλ��ɽ��Сʦ̫������ü��Ŀ�㡣\n");
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
			say( "��ɽŮ��΢Ц��˵������λ" + RANK_D->query_respect(ob)
            + "�����Һ�ɽ���𣬿��Կ�"BRED"(help hengshan)"NOR"��\n");
			break;
		case 1:
			say( "��ɽŮ��˵������ɽ��Ϊ���������е�һ֧���书�Խ���Ϊ����
���Ϲ����Ϊ����һ����\n");
			break;
		case 2:
			say( "��ɽŮ�����յ�������ɽ���������򽭺�����С֮���޲��ŷ���ӡ�
��ɽ����������λʦ̫�洫��ѧ��֮�ն��ܰ������֡�\n");
			break;
	}

}
