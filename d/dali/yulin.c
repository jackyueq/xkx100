//Room: /d/dali/yulin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
	set("long",@LONG
����һƬʪ������֣�����ˮ��������·���У�ʮ���ɸߵľ޴�
�����̸���ڣ����ɴֵü����˺ϱ�ҲΧ��ס����������֦�´�����
ˮ�з�������������Ϊ����ľ��¡�������Ȼ�������ޣ�ȴ�Ƿ��ݾ�
�ӵ���������������̨��������Խ�ڴ�������¶�ĸ�֦�ϣ��ö���
���Է���
LONG);
	set("objects", ([
	   __DIR__"npc/lieshou": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"luwang",
	]));
	set("coor/x", -37990);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/yl",1);
	}
}