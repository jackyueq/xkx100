// Room: /d/yueyang/huaiputing.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
������ͤ���ǵ���Ÿ�������꣬ƶ���ʵ�����Ϊ���������ˡ���
����¥���Ȳ���ʫƪ(poem)���Ÿ����������������ɴ�ʰ�����ϼ�����
��¥��
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("item_desc", ([
		"poem" : "
                        ������¥
����
                 ����      �����Ÿ�

                 ���Ŷ�ͥˮ����������¥��
                 ��������壬Ǭ����ҹ����
                 ������һ�֣��ϲ��й��ۡ�
                 �����ɽ����ƾ����������\n"
	]));
	set("exits", ([
		"east"   : __DIR__"loumen",
		"westup" : __DIR__"yueyanglou1",
	]));
	set("coor/x", -1440);
	set("coor/y", -2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
