// /guanwai/tianchi1.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������ڳ���ɽ�����ĵ㣬Ⱥ�廷������ظ�Լ��ʮ��������
������ر̲�ӯӯ���峺տ��������Χ�ͱڰ��ɣ���Ӱ��Ӱ��ӳ���У�
����ɽɫ���Ӱ����ʮ�����ˡ��������ⷼ�����𣬰ٻ����ޡ�����ʫ
�ƣ������İ�ʮ��ͱ����رߡ�ˮ������أ��Ƶͱ����졣��ɽ����
����¹���ǰԵ���買Я����������ο���ꡣ��
LONG );
	set("exits", ([
		"south"    : __DIR__"tianchi2",
		"northup"  : __DIR__"longmen",
		"westup"   : __DIR__"baiyun",
		"eastup"   : __DIR__"huagai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}