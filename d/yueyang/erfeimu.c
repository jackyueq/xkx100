// Room: /d/yueyang/erfeimu.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����Ĺ");
	set("long", @LONG
����Ĺ�ھ�ɽ���Ķ�´���������ųǸ���������Ĺ���ߵ�ʯ�̶���
�ǣ����������Ƿ�ǧ�ţ�ɽ�������һ�ˡ����⡰��һ�ˡ��������˴
��Ѳ�����ڲ��࣬��������������ʺ�ŮѰ����������ɽ������ج�ģ�
��ʹ��֣�������ʹ�ޣ���Ѫ���������ϣ����ɰ��񡣶�����������
�ھ�ɽ����ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"banzhu2",
		"west"      : __DIR__"banzhu3",
		"south"     : __DIR__"banzhu1",
		"northup"   : __DIR__"shanliang",
		"southwest" : __DIR__"shijie2",
		"northeast" : __DIR__"xiaolu6",
	]));
	set("coor/x", -1670);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
