// Room: /yangzhou/xiaohongqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","С����");
	set("long",@LONG
С������һ��ľ�ƹ��ţ�����Դ���Ŷ����������Ͻ��һ��룬��
��С��ɽ��������ԭΪ�������ɽˮ�����˺ӵĺӵ�ױ����ɡ�������
С���㣬�������������γ����ۣ�ˮ����ӳ��̨ͤ���£������迣����
����԰�֣�����������һƬ��
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"northup" : __DIR__"changchunling",
		"south"   : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}