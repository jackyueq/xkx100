// Room:  /d/luoyang/dukang.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "�ſ���ׯ");
	set("long",  @LONG
�ſ���ׯ�Ǿ��������ַ���Ǿ��Ļ���Դ�ء����ſ���ׯ��Ϊ��ƽ
����ͣ�λ����������һ����ſ��塣ɽ���������ߵ������¥������
ׯ���жſ�������ɽ���ȣ������أ�ӣ��Բ������̨��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"road7",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
