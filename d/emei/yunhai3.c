inherit ROOM;
void create()
{
        set("short", "�ƺ�");
        set("long", @LONG
������Ƕ����������ƺ��ˣ�������ȥ����ɽ��Ұ��
������������Ū�����Լ����ںγ�������������ԼԼ��
һ��С��ͨ��ǰ�������ǻ�ȥ�ɡ�
LONG
        );
        set("exits", ([
  "south" : __DIR__"yunhai1"+random(3),
  "west" : __DIR__"yunhai"+random(3),
  "north" : __DIR__"yhrkou",
  "east" : __DIR__"yunhai"+random(3),
]));
        set("objects", ([
                "/clone/medicine/vegetable/lingzhi" : random(2),
        ]));
	set("coor/x", -6200);
	set("coor/y", -1180);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}