// midao5.c �ܵ�

inherit ROOM;

void create()
{
	set("short", "����ͨ��");
	set("long", @LONG
����һ��ʯ�ң���Լ���Ըо��������Ǳ������Ӳ��ʯ�ڣ���
�Ϻͽ��䶼�ǻҳ�����źþ�û�������ˡ�
LONG );

	set("exits", ([
	       "east" : __DIR__"midao4",
	       "out"  : __DIR__"neiting",
	]));
	set("objects", ([
//	       NOSTRUM_DIR"binghuojiu" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -3090);
	set("coor/y", -25000);
	set("coor/z", -20);
	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="out")
		tell_object(me,"���߳�������ͨ�������صس���������֮�С�\n");
	return ::valid_leave(me,dir);
}
