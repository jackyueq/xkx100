//Room: /d/dali/hole.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��С֥�ƶ�");
	set("long",@LONG
���Ż��۽��붴�ڣ��ػ����У����ã�����һ����Ȼ���ʣ�ʯ��
�飬ʯ��ʯ����������͸��������ʤ�����ձ�Ӱ�����´����ң�Ϫ
�ƽ�ˮ�������ֺ���ʯ��δ䣬���Ŀɰ���
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "out"      : __DIR__"changhu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38000);
	set("coor/y", -53990);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/zyd",1);
	}
}