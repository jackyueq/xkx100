// /kaifeng/cangjing2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�ؾ�¥����");
	set("long", @LONG
С¥���ĸ������з���ʯ�Ұ����������տ����е�ˮ�ݡ�ÿ����ʱ
�䣬�����еĺ��л���ղ��ں��еķ𾭷ŵ�����ȥɹ�Է��վñ�����
���ˣ�������ɹ�𾭵�ʯͷ�ͳ�Ϊɹ��ʯ����˵�з�����
LONG);
	set("objects", ([
		BOOK_DIR"fojing2" : random(6),
	]));
	set("exits", ([
		"down" : __DIR__"cangjing1",
	]));

	setup();
	replace_program(ROOM);
}
