//  Room:  /d/lanzhou/jintian.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�����");
	set("long",  @LONG
���߹����֣��������ֺ�һ��ɽ�ţ�����------����ۡ��ഫ����
ʼ���ڽ��Ķ��꣬���롰���桱�����ֳ���̳��������䣬��������ۡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"street3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -9300);
	set("coor/y", 2710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}