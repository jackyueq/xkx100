//  Room:  /d/luoyang/northgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
���˴��ţ��Ͳ��������ǵĹ�Ͻ��Χ�ˣ��ſ�վ�ŵ����سǹٱ���
վ�ڳ�¥����ȥ��������һƬé��·����˵����ͨ�����أ��ٱ��ر�Ҳ
�����ϡ������̷�������������С·�������������ʷ��������Ǹ��ء�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"road5",
		"south"  :  __DIR__"northroad",
	]));
	set("objects",  ([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
