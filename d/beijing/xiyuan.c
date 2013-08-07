inherit ROOM;

void create()
{
	set("short", "����ϷԺ");
	set("long", @LONG
������������ĳ���ϷԺ������Ϸ����̨�� (stage)��Ϸ��̨�º�
ѹѹ��һƬ�����ˡ�������������ǽ���ס�����Ȳɡ������Ǻ�̨��
LONG );
	set("exits", ([
		"up"    : __DIR__"stage",
		"east"  : __DIR__"houtai",
		"south" : __DIR__"xichang1",
	]));
	set("item_desc", ([
		"stage" : "\n����Ϸ̨����ͻȻ�������̨���ݵĳ嶯��\n" ,
	]));
	set("objects", ([
		__DIR__"npc/guanzhong":  5,
	]));
	set("guanzhong", 2);
	set("coor/x", -210);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object man, *ob;
	if(dir=="up")
	{
		if(!me->query_temp("hastryup"))
		{
			me->set_temp("hastryup",1);
			if((int)me->query("meili")>=40)
			{
				message_vision("ֻ��������һƬ������������һ����ơ����˴���˵����\n��һ�����뿴��λ"+RANK_D->query_respect(me)+ "���ݡ�\n",me);
				return ::valid_leave(me, dir);
			}
			else
			{
				if(query("guanzhong") > 0)
				{
					add("guanzhong", -1);
					message_vision("\nͻȻ����һӵ���ϣ���$N��е���ƾ��Ҳ����̨���£�������������"+RANK_D->query_rude(me) + "��\n",me);
					if(!present("jia", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong1");
						man->move(this_object());
					}
					if(!present("yi", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong2");
						man->move(this_object());
					}
					if(!present("bing", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong3");
						man->move(this_object());
					}
					if(!present("ding", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong4");
						man->move(this_object());
					}
					if(!present("wu", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong5");
						man->move(this_object());
					}
					ob = all_inventory(this_object());
					for(i=0; i<sizeof(ob); i++)
					{
						if( !userp(ob[i]) )
						{ 
							ob[i]->set_leader(me);
							ob[i]->kill_ob(me);
							me->fight_ob(ob[i]);
						}
					}
				}
				return notify_fail("������һ�󵹲ʡ�\n");
			}
			return notify_fail("������ƴ��Ҳ��������̨��\n");
		}
		message_vision("$Nƴ������̨ȥ��\n",this_player());
		return ::valid_leave(me, dir);
		} 
	return ::valid_leave(me, dir);
}
