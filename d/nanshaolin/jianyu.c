// Room: /d/nanshaolin/jianyu.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ���Կ�����
���ƺ��м�����Ӱ��������ת��ͷȥ������������ס���������ŵص����㡣
�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ������ɣ�ֻ���ϱ������һ��С�ţ�
���Ͽ��˸����ƴ�Ķ��������ͷ��õġ��ű���һ�Ѷ�������ȥ�����ݵ�ɢ
�˿�����ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG );
	set("valid_startroom",1);
	set("objects",([
		CLASS_D("nanshaolin") + "/fangcheng" : 1,
		"/d/shaolin/obj/fojing1"+random(2) : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6220);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob = this_player();

	if(userp(ob))
	{
		message("vision", HIY"ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n\n"NOR, environment(ob), ob);
		tell_object(ob,"���ɺٺٵ�Ц�ţ���������������������...��\n");
		ob->set("startroom", "/d/nanshaolin/jianyu");
		ob->apply_condition("nbonze_jail", ob->query_condition("nbonze_jail")+60);
	}
}
