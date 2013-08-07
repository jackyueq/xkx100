// autosaved.c
// file:		Autosave daemon

// Ψһ��������ͷ紫ͨ�� �Զ�������condition�� 
#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <command.h>

#pragma save_binary

inherit F_DBASE;

void auto_save();
void check_dns();

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "�ڴ澫��");
	CHANNEL_D->do_channel(this_object(), "sys", "����Ƶ��ϵͳ�Ѿ�������\n");
	remove_call_out("auto_save");
	call_out("auto_save", 10);
}

void auto_save()
{
	string *ms = ({
HIM"���ˣ������Ӣ��ô��������������������Ķ������͹����һ�����ˡ���",
HIM"���ˣ����Թ��ĸ�����û�в�Ф֮ͽ������������ʦ�����ܷ�Э�������Ż�����ɱ������ͽ��׷�ر����ؼ�����",
HIM"�����ϣ����Ҹ����ھֽ�����Խ�������ˣ������ֵĻ��ȴ����ˣ�����������Ϊ��ʦ����ͼ���󣡡�",
HIM"���ۣ��������ɲ��ã��������У�����֪������������ļ���죬ά���ΰ�������нˮ��Ҳ��¶������",
HIR"ĳ�ˣ����������������ʦ�ѽ�֮���ˡ���ͽ���޷��õ�ʦ���洫����˵���������˶�������ͽ�ˡ���",
HIR"����¥���ϰ壺��С��а����硢���硢���磬��Ǯ�Ĵ���ү�������ǿ�������ģ���",
HIR"�販ʿ���������ַ�����ӡ����ơ����������꣬����Ӧ�о��С��β�ȥ������������",
HIR"�����СС�����ң�Ҳ���гߴ繦�͡����������űߣ���ɢ������Ե���ˡ���",
HIG"�����ࣺ���Ϸ��ң����Ӻ��ݣ�������������֪�˵ģ��������ơ���",
HIG"ĳ�ˣ���������������Ժ��Ҳ̫���ˣ�������ү�Ҿ�ϲ�����ˣ�����£��������Ҳ�պ��ˡ���",
HIC"��԰�����������䵱���˲ι�Ϊ��ľ֮�棬�����ұ�����֮������������鵤����",
HIC"���壺����˵�����������ܵ������˴󳤹�������",
HIC"ĳ�ˣ�������㻹û��ð��ĸ����ɣ����ȵ�������ݻ�ɶ���ţ���ѧ�����������",
HIG"ŷұ�ӣ������¹������ҴӲ��������롣��Ҫ���ֱ��У������ؽ�ɳĮ�����ҡ���",
HIG"ĳ�ˣ�����˵�������һ�������Լ��Ƿ����ӣ����Ǵ�����ˣ�ͬȥͬȥ����",
HIB"���ˣ��������Ϸ�����������ҵ�䷢ѧλ�������ֵ�Ҳȥ������ƾ��Σ���",
HIB"÷���磺��������ʦ�������˼Ҿ�ͨ�������ԣ���ָһ�㣬��֪�������ڡ����ǻ��������ӵ�ԽԶԽ�á���",
HIY"����������¾Ž�Ϊ���½���֮�Ҫ���ʤ�ٰܣ�������ʮ�꣬��ɺ�����Ӣ��һ�ϳ����ˡ���",
HIG"Ľ�ݸ������Ա�֮������ʩ�������������������о��е���Ȥ��������Ӣ��һ�Ըߵͣ���úú�ѧ�ö�ת���ơ���",
HIG"�����̣������Ҽҵ������񶴺�������Ļ�ʩˮ���ղ������������ɵ��ؼ�����",
HIY"���޼ɣ���Ǭ����Ų��Դ�Բ�˹���ɻ��й��������Σ�����Ʒ������Ա�֮�����Ƶ���Ʈ��֮�䣬������һ��һ����Ų���򡣡�",
HIR"���߹�����ؤ�������µ�һ���ᡣ̽��������Ϣ�Ǳ�������ֱ��£�������ܵ����������֮������ͨ�˴��",
HIG"�����䣺������������Ͷ仨����ά�ﻨ�����ʱ�ʻ��ܡ���",
HIG"�����������Ϸ��ڹ���Ϊ��ǿ���⣬���֮��ȴҲ��С����",
/*HIW"
    ��Ĺ�ľӳ�����
    ����������̫��
    ����������ʱ·
    �ƹ�Ӣ��������
    ��������ǧ����
    �������аپ�ʫ
    ������˷Ÿ账
    ��̶ֿ�ѳ���˼"*/
	});
	string hui_chun, yan_yang;
	int huichun, yanyang, usernum, i, t, e, p;
	object *ob, *inv;
	object linkob;

message("channel:snow", HIY"�����š�"+ms[random(sizeof(ms))]+"\n"NOR,users());
	if (file_size("/d/shenlong/cangku.c"))
	  if (!find_object("/d/shenlong/cangku"))
	    load_object("/d/shenlong/cangku");
	if (uptime()<400)
	{
		write_file("/data/XUMING", "1", 1);
		write_file("/data/HUICHUN", "0", 1);
		write_file("/data/YANGYAN", "0", 1);
	}
	hui_chun = read_file("/data/HUICHUN", 1, 1);
	huichun = atoi(hui_chun);
	if(huichun == 0 && uptime() > 86400)
	{
		write_file("/data/HUICHUN", "1", 1);
	}
	yan_yang = read_file("/data/YANGYAN", 1, 1);
	yanyang = atoi(yan_yang);
	if(yanyang == 0 && uptime() > 43200)
	{
		write_file("/data/YANGYAN", "1", 1);
	}
// ������߻򷢴�20�������ϵ���� ���������ʱ��ʧ
//	ob = objects();
	ob = children(USER_OB);
	for (usernum=0; usernum<sizeof(ob); usernum++)
	{
		if (!clonep(ob[usernum])) continue;
		if (!environment(ob[usernum])) {destruct(ob[usernum]);continue;}
		if(userp(ob[usernum]) && !wizardp(ob[usernum]))
		{
			if( !interactive(ob[usernum])  ||
				( query_idle(ob[usernum]) > 2400 && !environment(ob[usernum])->is_chat_room()))
			{
				if (!interactive(ob[usernum]) && random(3)>0)
				continue;
				if (time()-ob[usernum]->query_temp("LAST_PKER_TIME")<7200)
					continue;
				"/cmds/usr/exit"->savequit(ob[usernum]);
			}
			else
			{
				inv = all_inventory(ob[usernum]);
				for(i=0; i<sizeof(inv); i++)
				{
				 if ( ob[usernum]->is_fighting())
                			inv[i]->set_temp("keep",0);
        			 else
        			  {					   
					  if( !inv[i]->is_unique()	
					  &&  inv[i]->query("weapon_prop/damage") >= 100
				    &&  !inv[i]->query("ownmake"))
					     inv[i]->add_temp("keep", 1);
					  if( inv[i]->query_temp("keep") > 6 )
				  	{
					  	message("channel:snow",HIM"��ҥ�ԡ�ĳ�ˣ�"+"��ʧ�����"NOR+inv[i]->name()+HIM"�����ֽ�������\n"NOR, users());
				  		log_file( "WEAPON", sprintf("%20s leave %10s at %s.\n", ob[usernum]->query("name")+ "(" + ob[usernum]->query("id")+")", inv[i]->name(), ctime(time())));
					  	destruct(inv[i]);
					  }
				   }
				}
			}
		}
	}

// ��ͻ�������
	check_dns();
// �жϺƽ�ϵͳ�Ƿ�����
	if ( LOGIN_D->get_dienpc() > 3000 ) call_out("haojie",0);
	remove_call_out("auto_save");
	call_out("auto_save", 1200+random(20));
}

void check_dns()
{
	mapping mud_list;
	mixed *muds;
	object dns;

	if(!dns = find_object(DNS_MASTER))
	// dns not started, not our problem
	return;
	mud_list = (mapping) DNS_MASTER->query_muds();
	muds=keys(mud_list);
	if(sizeof(muds)<= 1)
	{
		destruct(dns);
		call_other(DNS_MASTER,"???");
	}
	return;
}
// �ƽ�ϵͳ�Ŀ�ʼ
void haojie()
{
	message("channel:snow",HIM"��ҥ�ԡ�����������һ���������غ�Σ�յ����磬̫�õ�ƽ���ƺ�Ԥʾ�ű�������\n�ٵ�ǰϦ�����ڽ��������ɼ�������Ҫȥ���һ��һ�ε���ս��Σ����˭����֪����\n���Ƿ���Ȼ����˵İ����أ�\n\n"NOR,users());
	message("channel:snow",HIM"��ҥ�ԡ��������������һ��������֯��������������ɣ�һͳ������\n\n\n"NOR,users());
	DISASTER_D->disaster(0);
}

