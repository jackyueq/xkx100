//ROOM: /d/yanziwu/huanshi.c

inherit ROOM;

void create()
{
	set("short", "��ʩˮ��");
	set("long",@LONG
��������������������ǵ�Ľ�ݼҲ���֮��������ϰ��֮�ˣ�����
���Ա�֮������ʩ����֮���ߣ�Ī��ϣ�����ˣ�����Ľ�����Ҿ�����
���ܡ�����������ܣ����ϰ��������Ϊ�žɵ��鼮�����Ͼ����б�ǩ
(sign)�������Ľ�����������������ռ����۶��ɵ���ѧ���⡣
LONG );
	set("exits", ([
		"north": __DIR__"jiashan",
	]));
	set("objects", ([
		__DIR__"book/leg_book": random(2),
		__DIR__"book/cuff_book": random(2),
		__DIR__"book/claw_book": random(2),
		__DIR__"book/hand_book": random(2),
		__DIR__"book/dodge_book": random(2),
		__DIR__"book/finger_book": random(2),
		__DIR__"book/strike_book": random(2),
		__DIR__"book/unarmed_book": random(2),
	]));
	set("item_desc",([
		"sign" : "ǩ�ϱ������֡��䵱����ǡ���������ɵ����ơ�\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1541);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
