// Room: /d/huijiang/fangju.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "���߿�");
	set("long",@LONG
�����Ǻ컨��ķ��߿⡣�컨��Ϊ�˷��帴�������˺ܶ������ϵ�
׼��������������ž���������ᡣ����ֿ�ѵ���������������
���ģ����з�������Ӧ�о��С�
LONG );
        set("objects", ([
		ARMOR_DIR"beixin"  : random(2)+1,
		ARMOR_DIR"tengjia" : random(2)+1,
		ARMOR_DIR"tiejia"  : random(2)+1,
		ARMOR_DIR"niupi"   : random(2)+1,
        ]));
	set("exits", ([
		"south" : __DIR__"wuchang",
	]));
	set("coor/x", -50040);
	set("coor/y", 9150);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
