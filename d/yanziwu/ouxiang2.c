// Room: /d/yanziwu/ouxiang2.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "ź��С��");
	set("long", @LONG
ź��С������С�����硣С�����������������񣬺���ͷ�߶���
��ʱ�ͻ��������һƬ��С�������ٴ�������һ���Ű��񣬰ڷ��ŵĶ�
���书�ؼ�����ͷһ֧С���۴ֵ������Ѿ�����һ�룬���������ᴹ��
����������֧����̶����鰸�ϡ�
LONG );
	set("exits", ([
		"down"  : __DIR__"ouxiang1",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", 1200);
	set("coor/y", -1230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}