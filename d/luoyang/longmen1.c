// Room:  /d/luoyang/longmen1.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "����ɽɫ");
	set("long",  @LONG
��������ˮ��������֮��ɽ������ɽ���ţ��������ڣ��ʹųơ���
�ڡ��������Ժ�ϰ�����š��ǽ��������������۹ء���ˮ�������У�
����һ���������Ŷ�����ͨ�ơ����š����׾�����˵����������ɽˮ֮
ʤ���������ɡ������������ɽɫ�����类��Ϊ�����˴�֮�ס�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"road3",
		"north"  :  __DIR__"road4",
		"west"   :  __DIR__"pingquan",
		"eastup" :  __DIR__"longmen",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -45);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
