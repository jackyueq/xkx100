// Feb. 6, 1999 by Winder
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("����", ({ "a feng","a","feng"}) );
	set("gender", "Ů��" );
	set("age", 16);
	set("long", "����һ�����ÿɰ���Ů���ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
	    "����һ��΢Ц�ţ�һ�߲�֪������ʲô���¡�\n",
	    "�������������˵�������Ǹ����ˣ����˼ҵ����ⶼ��֪����\n",
	    "����̾�˿�������Ů��˼������\n",
            "����ͻȻ˵�����Ҽ�С��òҰ���������������ϲ����ȥ��\n"
	   }) );
       set("inquiry",([
	   "����" : "�����ҵ������˰������Ҳ�֪������������Σ������������һ��Ů���Ӽ���ô˵�ó����\n"
	   ]) );
       setup();
       carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object me, object ob)
{
        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0; 
        if ( !present(ob, me) ) return notify_fail("��û�����������");
        if ( (string)ob->query("id") == "qing shu") 
        {
         write(HIC "����һ�����������������飬���˵�����������˵��: \n" NOR);
         write(HIC "��Ȼ�������ô�ã��Ҿ͸�����һ�����ܡ������ǿ���\n" NOR);         
         write(HIC "��ȥ�ġ���ֻ���ڡ���ͤ�����¿ľŸ�ͷ�Ϳ����ˣ�\n" NOR);
        }               
        return 1;
}
