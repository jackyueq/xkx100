// Room: /d/wudujiao/caodi.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
���������е�һƬ�յأ����ܱ�����Ĺ��ɻ����ţ�������һƬ��
���͵Ĳݵء��ݵ����������һ��ȭͷ��С��С�����Ա�����Բ���
������¶�����ɫ������������һƬ�ž����ݵ����������ģ��������
��ȴһҲ�����ɣ�����ò�����ʲôΣ�հɣ�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"sl7",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}