// Room: /d/lingxiao/.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "ʯ�¿�ջ");
	set("long", @LONG
������ѩɽɽ·�ϵ�һ���ջ����Ȼ�������ʵ��ƽ��Ҳ������
��ʲô�ο�����ѩ����ɽ��ˮ���������ѩɽ�ϣ�ȴҲ�Ƕ�һ�޶��Ŀ�
ջ��������ط���Ҫ�ǲ��붳��������������ϣ�ֻ�»��ǵ��չ�һ��
��������⡣������ҵ굹Ҳ��������¡��
LONG );
	set("exits", ([
		"west" : __DIR__"shiya",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -30990);
	set("coor/y", -8980);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

