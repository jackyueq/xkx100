// Room: /d/wuxi/westroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "���½�");
	set("long", @LONG
����һ����������ש�ֵ����붫��·һ���Ϊ��ͨ�����Ƕ�����Ҫ
���������̷���������������С�Ӵ��ֶ�������˵������һ�š�Ҳ��
Ϊ�����ǻ۵����﹤�����������·��������ؽ����һ��ʹ������
����һ��Ҳ�����ò��㡣�ϱ���һ��������Ǯׯ����������·�����Ǽ�
�����������ˣ����չ����Լ���Ӫ�������治ʱ�ش���ϡ����������Ǯ
��������������һ�ҵ��̣�ϸ������������ѹ�͵��ּۻ��۵�������
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"dangpu",
		"south" : __DIR__"qianzhuang",
		"west"  : __DIR__"westroad2",
		"east"  : __DIR__"guangchang",
	]));
	set("coor/x", 360);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}