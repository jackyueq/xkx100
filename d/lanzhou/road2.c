//  Room:  /d/lanzhou/road2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�����");
	set("long",  @LONG
����һ����������ʯ��ֵ���������һֱ�����졣����·������
��ʱ�й��������߹����͸ղų�������ľ����γ������Աȡ������Ǹ�
���ֵĹ㳡��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"southgate",
		"north" : __DIR__"square",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2680);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}