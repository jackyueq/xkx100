// qianting.c ǰ��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long", @LONG
�����ǹ�Ĺ��ǰ����������ģ��㼸��ʲôҲ�����塣ȫ������
���м������������һ��ҹ���飬ӳ��������Ļƹ⡣����������˶
���ʯ�����ɵģ������ƺ���д��һЩʲô��(zi)���谵����������
�ֱʡ����㲻��ϸ����ôҲ���������
LONG	);
	set("item_desc", ([
		"zi": "��ˮΪ����Ϊ��    ܽ����������ü\n"
	]));
	set("exits", ([
		"west"  : __DIR__"mudao02",
		"east"  : __DIR__"mudao05",
		"south" : __DIR__"mudao04",
		"north" : __DIR__"mudao01",
	]));
	set("objects", ([
		CLASS_D("gumu")+"/first" : 1,
	]));
	set("coor/x", -3220);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
