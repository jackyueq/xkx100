// Room: /qingcheng/tianran.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��Ȼͼ��");
	set("long", @LONG
�����ұڴ���������ӳ�ԣ��Ƹ���ɽ���ΡȻ�������Ĺ˷���
ʯ�죬������翣�Զ�����ͣ����ڻ��С����������š���һʯ��
��ɲ�ʯ��֮�䣬ʮ���վ���
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"eastdown" : __DIR__"path1",
		"westup"   : __DIR__"path2",
		"north"    : __DIR__"zhuhezhuang",
	]));
        set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -910);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}