//  Room:  /d/luoyang/northroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "���ݽ�");
	set("long",  @LONG
��֪��Ϊʲô����������·�ϣ��ܸо����˵�ʲô��Ҳ����������
��ս�ң�ʹ�ñ��������ֵĽ����������壬��·���Եĵ��������ƾɲ�
����һ����ȥ��֪���кܾ�û���˾�ס�ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"northgate",
		"south"  :  __DIR__"center",
	]));
	set("objects",  ([
		"/d/huashan/npc/youke" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
