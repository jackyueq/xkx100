// Room: /qingcheng/tianshidong.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ʦ��");
	set("long", @LONG
��ʦ���Զ��������ڴ˽��������������������ų����ۡ�����
ɽ����Ԫ�����ͱڼ䡣������ʦ�����ұ����ȿ�ͨ������������
����ܻ��ȣ��۾��̨�����ƺ�ΰ���ڹ����ˡ���ũ����ԯ����
ʯ������
LONG );
	set("exits", ([
		"northup"  : __DIR__"gulongqiao",
		"north"    : __DIR__"sanqingdian",
		"eastdown" : __DIR__"path2",
		"west"     : __DIR__"yinxing",
		"east"     : __DIR__"sandaoshi",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : random(3),
	]));
	set("coor/x", -8100);
	set("coor/y", -910);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}