// Room: /d/lingxiao/sroad2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
��ʱѩ����Щ�ˣ�ʹ�õ��ϸ����˺���һ�㡣��ֵ������������
ɽ�����������ı���������̫���������ͷ��䣬�������㶼���ǳ��
ɫ��͸���壬��Щĩ�������ѩ������������£�����ϼ�����ʣ�����
���������ݡ�ɽ·Ҳ������ƽ̹��������һ�������������뵽��ʫ��˵
����ȥʱѩ����ɽ·����Ҳ������˰ɡ�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
	    "southdown" : __DIR__"sroad1",
	    "northup"   : __DIR__"sroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8990);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

