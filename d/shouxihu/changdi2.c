// Room: /yangzhou/changdi2.c
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
		"north" : __DIR__"taohuawu",
		"south" : __DIR__"chunliuting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 33);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}