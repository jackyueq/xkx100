// shenjiao.h ���
int do_join(object ob, object obj)
{
	object me;
	string pname ;
	mapping party;
	string *partyname = ({ HIG"����", HIW"�׻�", HIC"����" });

	me = this_object () ;
	ob = this_player () ;

	if(ob->query("party") && ob->query("party/party_name")==HIB"�������"NOR)
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������̵����ˡ�\n",me,ob);
		return 1;
	}
	if(ob->query("party") && ob->query("party/party_name")!=HIB"�������"NOR)
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ�����������������̡�\n",me,ob);
		return 1;
	}
   	if( !mapp(party = ob->query("party")) )
   	{
		if ( (string)ob->query("gender") == "Ů��" ) pname=HIM"����";
		else pname=partyname[random(sizeof(partyname))];
		if ( (string)ob->query("gender") == "Ů��" )
			command("say ������ֵ�һŮ�к��ܣ����ǿ�ϲ�ɺ� !");
		else 
			command("say ������ֵ�һӢ�ۺú������ǿ�ϲ�ɺ� !");

		party = allocate_mapping(5);
		party["party_name"] = HIB "�������" NOR;
		party["rank"] = pname+"�ý���"NOR;
		party["level"] = 1;
		party["tasks"] = 0;
		party["enter_time"] = time();
		ob->set("party", party);

		command("smile");
		message_vision("$N��$n˵�����Ҷ�����̣�����ʱ�ȱ������"+pname+"�ã�\n", me, ob);
		return 1;
	}
        command("?");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
	return 0;

}

