// Room:  /d/luoyang/pingquan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "ƽȪ����");
	set("long",  @LONG
������������ʮ��������ߵ�ɽ���£��и������ʹ塣����ɽ��
��������ľ��ӳ��ȪˮԴ�ڣ���Ϫ�ӻأ�����������ʱ�������ԣ��
��������ƽȪ���Ρ���������˾�֮һ��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" :  __DIR__"longmen1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -510);
	set("coor/y", -45);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
