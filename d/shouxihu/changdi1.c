// Room: /yangzhou/changdi1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "���̴���");
	set("long", @LONG
�����ţ���������Ȼ���������̱�ֲ�����������һ�������������
��֮˵����˵������쾵ۿ��˺ӣ��ӵ�ֲ������쾵۴ʹ����������
��֮��ʼ�����ݡ�������˿��ˮ���������֣���ν��������������������
������ˮ����һͤ�����������С������е�׺����һ����Һ����̣���
Ӱˮ�У������쾳��
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"south" : "/d/city/hongqiao",
		"north" : __DIR__"chunliuting",
	]));
	set("objects", ([
		"/d/city/npc/lady1" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 31);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
